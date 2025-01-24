using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using System.Drawing;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using HW4Project.Models;

namespace HW4Project.Controllers
{
    public class ColorInterpolatorController : Controller
    {
        //From Greg's answer: https://stackoverflow.com/questions/359612/how-to-change-rgb-color-to-hsv/1626175
        //And Wikipedia: https://en.wikipedia.org/wiki/HSL_and_HSV
        public static void ColorToHSV(Color color, out double hue, out double saturation, out double value)
        {
            int max = Math.Max(color.R, Math.Max(color.G, color.B));
            int min = Math.Min(color.R, Math.Min(color.G, color.B));
            hue = color.GetHue();
            saturation = (max == 0) ? 0 : 1d - (1d * min / max);
            value = max / 255d;
        }

        public static Color ColorFromHSV(double hue, double saturation, double value)
        {
            int hi = Convert.ToInt32(Math.Floor(hue / 60)) % 6;
            double f = hue / 60 - Math.Floor(hue / 60);
            value = value * 255;
            int v = Convert.ToInt32(value);
            int p = Convert.ToInt32(value * (1 - saturation));
            int q = Convert.ToInt32(value * (1 - f * saturation));
            int t = Convert.ToInt32(value * (1 - (1 - f) * saturation));
            if (hi == 0)
                return Color.FromArgb(255, v, t, p);
            else if (hi == 1)
                return Color.FromArgb(255, q, v, p);
            else if (hi == 2)
                return Color.FromArgb(255, p, v, t);
            else if (hi == 3)
                return Color.FromArgb(255, p, q, v);
            else if (hi == 4)
                return Color.FromArgb(255, t, p, v);
            else
                return Color.FromArgb(255, v, p, q);
        }

        [HttpGet]
        public IActionResult Create()
        {
            Debug.WriteLine("Inside get");
            return View();
        }
        [HttpPost]
        public IActionResult Create(ColorInterpolation c)
        {
            Debug.WriteLine("Inside post");
            Debug.WriteLine(c);
            if (ModelState.IsValid)
            {
                Debug.WriteLine("model is valid");
                List<string> list = new List<string>();
                Color color = ColorTranslator.FromHtml(c.FirstColor);
                Color colortwo = ColorTranslator.FromHtml(c.SecondColor);
                double h, s, v;
                double h2, s2, v2;
                ColorToHSV(color, out h, out s, out v);
                ColorToHSV(colortwo, out h2, out s2, out v2);
                Debug.WriteLine(h + "<-h s-> " + s + " v-> " + v);
                Debug.WriteLine(h2 + "<-h2 s2-> " + s2 + " v2-> " + v2);
                double hueAdd = Math.Abs(h2 - h) / c.Amount;
                double satAdd = Math.Abs(s2 - s) / c.Amount;
                double valAdd = Math.Abs(v2 - v) / c.Amount;
                Debug.WriteLine(hueAdd + "<-hueAdd satAdd-> " + satAdd + " valueAdd-> " + valAdd);
                double h3 = h, s3 = s, v3 = v;
                list.Add(c.FirstColor);
                for (int i = 0; i < c.Amount; i++)
                {
                    if (h > h2)
                    {
                        h3 -= hueAdd;
                    }
                    else
                    {
                        h3 += hueAdd;
                    }
                    if (s > s2)
                    {
                        s3 -= satAdd;
                    }
                    else
                    {
                        s3 += satAdd;
                    }
                    if (v > v2)
                    {
                        v3 -= valAdd;
                    }
                    else
                    {
                        v3 += valAdd;
                    }
                    Color newcolor = ColorFromHSV(h3, s3, v3);
                    Debug.WriteLine(h3 + "<-hue sat-> " + s3 + " value-> " + v3);
                    string htmlColor = ColorTranslator.ToHtml(newcolor);
                    Debug.WriteLine("HtmlColor: " + htmlColor);
                    list.Add(htmlColor);
                    Debug.WriteLine("newcolor: " + newcolor);
                }
                c.HexList = list;
                return View("Create", c);
            }
            else
            {
                Debug.WriteLine("model is not valid");
                return View("Create", c);
            }
        }
    }
}