using System.ComponentModel.DataAnnotations;
namespace HW3Project.Models
{
    public class CompanyData
    {
        [Required(ErrorMessage = "Please enter your full name")]
        public string FullName { get; set; }
        [Required(ErrorMessage = "Please enter your phone number")]
        [Phone]
        public string PhoneNum { get; set; }
        [Required(ErrorMessage = "Please enter your personal email")]
        [EmailAddress]
        public string PersonalEmail { get; set; }
        [Required(ErrorMessage = "Please enter your company email")]
        [EmailAddress]
        public string CompanyEmail { get; set; }
        [Required(ErrorMessage = "Please enter your State")]
        public string State { get; set; }
        [Required(ErrorMessage = "Please enter your City")]
        public string City { get; set; }
        [Required(ErrorMessage = "Please enter your Date of Birth")]
        public string DOB { get; set; }
        [Required(ErrorMessage = "Please enter your company address")]
        public string CompanyAddress { get; set; }
    }
}