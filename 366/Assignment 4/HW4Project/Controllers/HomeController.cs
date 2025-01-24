using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using HW4Project.Models;

namespace HW4Project.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [HttpGet]
        public IActionResult RGBColor(int? red, int? green, int? blue)
        {
            if (red == null)
            {
                red = 0;
            }
            if (green == null)
            {
                green = 0;
            }
            if (blue == null)
            {
                blue = 0;
            }
            // Debug.WriteLine("rgb: " + " red = " + red + " green = " + green + " blue = " + blue);
            // int? RGB = red + blue + green;
            // Debug.WriteLine(RGB);
            ViewBag.RGB = red?.ToString("X2") + green?.ToString("X2") + blue?.ToString("X2");
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
