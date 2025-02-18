#pragma checksum "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "61f24b753d4e960418f6cb1e5792002fc41f17ff"
// <auto-generated/>
#pragma warning disable 1591
[assembly: global::Microsoft.AspNetCore.Razor.Hosting.RazorCompiledItemAttribute(typeof(AspNetCore.Views_Home_CompanyResults), @"mvc.1.0.view", @"/Views/Home/CompanyResults.cshtml")]
namespace AspNetCore
{
    #line hidden
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.Rendering;
    using Microsoft.AspNetCore.Mvc.ViewFeatures;
#nullable restore
#line 1 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\_ViewImports.cshtml"
using HW3Project;

#line default
#line hidden
#nullable disable
#nullable restore
#line 2 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\_ViewImports.cshtml"
using HW3Project.Models;

#line default
#line hidden
#nullable disable
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"61f24b753d4e960418f6cb1e5792002fc41f17ff", @"/Views/Home/CompanyResults.cshtml")]
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"10e34a42f6d04c27ecdfad228f98e211eddedf23", @"/Views/_ViewImports.cshtml")]
    #nullable restore
    public class Views_Home_CompanyResults : global::Microsoft.AspNetCore.Mvc.Razor.RazorPage<IEnumerable<HW3Project.Models.CompanyData>>
    #nullable disable
    {
        #line hidden
        #pragma warning disable 0649
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperExecutionContext __tagHelperExecutionContext;
        #pragma warning restore 0649
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperRunner __tagHelperRunner = new global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperRunner();
        #pragma warning disable 0169
        private string __tagHelperStringValueBuffer;
        #pragma warning restore 0169
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperScopeManager __backed__tagHelperScopeManager = null;
        private global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperScopeManager __tagHelperScopeManager
        {
            get
            {
                if (__backed__tagHelperScopeManager == null)
                {
                    __backed__tagHelperScopeManager = new global::Microsoft.AspNetCore.Razor.Runtime.TagHelpers.TagHelperScopeManager(StartTagHelperWritingScope, EndTagHelperWritingScope);
                }
                return __backed__tagHelperScopeManager;
            }
        }
        private global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.HeadTagHelper __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_HeadTagHelper;
        private global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.BodyTagHelper __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_BodyTagHelper;
        #pragma warning disable 1998
        public async override global::System.Threading.Tasks.Task ExecuteAsync()
        {
#nullable restore
#line 2 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
  
    Layout = null;

#line default
#line hidden
#nullable disable
            WriteLiteral("<!DOCTYPE html>\r\n<html>\r\n\r\n");
            __tagHelperExecutionContext = __tagHelperScopeManager.Begin("head", global::Microsoft.AspNetCore.Razor.TagHelpers.TagMode.StartTagAndEndTag, "61f24b753d4e960418f6cb1e5792002fc41f17ff3671", async() => {
                WriteLiteral("\r\n    <meta name=\"viewport\" content=\"width=device-width\" />\r\n    <title>Responses</title>\r\n    <link rel=\"stylesheet\" href=\"/lib/bootstrap/dist/css/bootstrap.css\" />\r\n");
            }
            );
            __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_HeadTagHelper = CreateTagHelper<global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.HeadTagHelper>();
            __tagHelperExecutionContext.Add(__Microsoft_AspNetCore_Mvc_Razor_TagHelpers_HeadTagHelper);
            await __tagHelperRunner.RunAsync(__tagHelperExecutionContext);
            if (!__tagHelperExecutionContext.Output.IsContentModified)
            {
                await __tagHelperExecutionContext.SetOutputContentAsync();
            }
            Write(__tagHelperExecutionContext.Output);
            __tagHelperExecutionContext = __tagHelperScopeManager.End();
            WriteLiteral("\r\n\r\n");
            __tagHelperExecutionContext = __tagHelperScopeManager.Begin("body", global::Microsoft.AspNetCore.Razor.TagHelpers.TagMode.StartTagAndEndTag, "61f24b753d4e960418f6cb1e5792002fc41f17ff4820", async() => {
                WriteLiteral(@"
    <div class=""text-center p-2"">
        <h2>List of Companies in database</h2>
        <table class=""table table-bordered table-striped table-sm"">
            <thead>
                <tr>
                    <th>Name</th>
                    <th>Phone Number</th>
                    <th>Personal Email</th>
                    <th>Company Email</th>
                    <th>State</th>
                    <th>City</th>
                    <th>Date Of Birth</th>
                    <th>Company Address</th>
                </tr>
            </thead>
            <tbody>
");
#nullable restore
#line 31 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                 foreach (HW3Project.Models.CompanyData r in Model)
                {

#line default
#line hidden
#nullable disable
                WriteLiteral("                    <tr>\r\n                        <td>");
#nullable restore
#line 34 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.FullName);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                        <td>");
#nullable restore
#line 35 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.PhoneNum);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                        <td>");
#nullable restore
#line 36 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.PersonalEmail);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                        <td>");
#nullable restore
#line 37 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.CompanyEmail);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                        <td>");
#nullable restore
#line 38 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.State);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                        <td>");
#nullable restore
#line 39 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.City);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                        <td>");
#nullable restore
#line 40 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.DOB);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                        <td>");
#nullable restore
#line 41 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                       Write(r.CompanyAddress);

#line default
#line hidden
#nullable disable
                WriteLiteral("</td>\r\n                    </tr>\r\n");
#nullable restore
#line 43 "C:\Users\Jacob\Documents\WOUProjects\CS366\366\Assignment 3\HW3Solution\HW3Project\Views\Home\CompanyResults.cshtml"
                }

#line default
#line hidden
#nullable disable
                WriteLiteral("            </tbody>\r\n        </table>\r\n");
            }
            );
            __Microsoft_AspNetCore_Mvc_Razor_TagHelpers_BodyTagHelper = CreateTagHelper<global::Microsoft.AspNetCore.Mvc.Razor.TagHelpers.BodyTagHelper>();
            __tagHelperExecutionContext.Add(__Microsoft_AspNetCore_Mvc_Razor_TagHelpers_BodyTagHelper);
            await __tagHelperRunner.RunAsync(__tagHelperExecutionContext);
            if (!__tagHelperExecutionContext.Output.IsContentModified)
            {
                await __tagHelperExecutionContext.SetOutputContentAsync();
            }
            Write(__tagHelperExecutionContext.Output);
            __tagHelperExecutionContext = __tagHelperScopeManager.End();
            WriteLiteral("\r\n</html>");
        }
        #pragma warning restore 1998
        #nullable restore
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.ViewFeatures.IModelExpressionProvider ModelExpressionProvider { get; private set; } = default!;
        #nullable disable
        #nullable restore
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IUrlHelper Url { get; private set; } = default!;
        #nullable disable
        #nullable restore
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IViewComponentHelper Component { get; private set; } = default!;
        #nullable disable
        #nullable restore
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IJsonHelper Json { get; private set; } = default!;
        #nullable disable
        #nullable restore
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IHtmlHelper<IEnumerable<HW3Project.Models.CompanyData>> Html { get; private set; } = default!;
        #nullable disable
    }
}
#pragma warning restore 1591
