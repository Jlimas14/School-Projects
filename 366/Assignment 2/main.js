// console.log("Hello, I am connected")

function validate() {
	// console.log("function used");
	if( document.userForm.userName.value == "" ) {
	   alert("UserName must be filled out");
	   document.userForm.userName.focus() ;
	   return false;
	}
	if( document.userForm.userPassword.value == "" ) {
	   alert("Password must be filled out");
	   document.userForm.userPassword.focus() ;
	   return false;
	}
	if( document.userForm.userEmail.value == "" ) {
		alert("Email must be filled out");
		document.userForm.userEmail.focus() ;
		return false;
	 }
	 if( document.userForm.favAnimal.value == "" ) {
		alert("Pick a favorite animal");
		document.userForm.favAnimal.focus() ;
		return false;
	 }
	 if( document.userForm.favColor.value == "" ) {
		alert("Pick a favorite color");
		return false;
	 }
// console.log( document.userForm.userName.value);
// console.log( document.userForm.userPassword.value);
// console.log( document.userForm.userEmail.value);
// console.log( document.userForm.favAnimal.value);
// console.log( document.userForm.favColor.value);
}

