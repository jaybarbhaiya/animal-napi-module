const Animal = require("../lib/binding.js");
const assert = require("assert");

assert(Animal, "The expected module is undefined");

function testBasic() {
    const cat = new Animal("Cat", false);
    assert(cat.getName, "The expected method is not defined");
    assert.strictEqual(cat.getName(), "Cat", "Unexpected value returned");
    assert.strictEqual(cat.canFly(), false, "Unexpected value returned");

    const eagle = new Animal("Eagle", true);
    assert.strictEqual(eagle.getName(), "Eagle", "Unexpected value returned");
    assert.strictEqual(eagle.canFly(), true, "Unexpected value returned");
}

function testInvalidParams() {
    const instance = new Animal();
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");
assert.throws(testInvalidParams, undefined, "testInvalidParams didn't throw");

console.log("Tests passed- everything looks OK!");