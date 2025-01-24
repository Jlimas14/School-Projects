using System.Collections.Generic;
namespace HW3Project.Models {
    public static class CompanyList {
        private static List<CompanyData> companies = new List<CompanyData>();
        public static IEnumerable<CompanyData> Companies => companies;
        public static void AddCompany(CompanyData company) {
            companies.Add(company);
        }
    }
}