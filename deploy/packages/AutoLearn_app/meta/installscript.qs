function Component()

{

// initializations go here

}

Component.prototype.isDefault = function()

{

// select (true) or unselect (false) the component by default

return true;

}

Component.prototype.createOperations = function()

{

try {

// call the base create operations function

component.createOperations();

} catch (e) {

console.log(e);

}

}
