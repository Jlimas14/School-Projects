using System;
using System.ComponentModel.DataAnnotations;
using System.Collections.Generic;

namespace HW4Project.Models
{
    public class ColorInterpolation
    {
        [Required]
        [StringLength(7, MinimumLength = 7)]
        [RegularExpression(@"^[#][a-fA-F0-9]{6}$", ErrorMessage = "Type hexadecimal in the same format as above")]
        public string FirstColor { get; set; }

        [Required]
        [StringLength(7, MinimumLength = 7)]
        [RegularExpression(@"^[#][a-fA-F0-9]{6}$", ErrorMessage = "Type hexadecimal in the same format as above")]
        public string SecondColor { get; set; }

        [Required]
        [Range(0, 100000)]
        public int Amount { get; set; }

        public IEnumerable<string> HexList { get; set; }

        public override string ToString()
        {
            return $"first color = {FirstColor}, second color = {SecondColor}, amount = {Amount}";
        }
    }
}
