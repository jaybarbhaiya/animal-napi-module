const addon = require('../build/Release/animal-native');

function Animal(name, bCanFly) {
    this.getName = function () {
        return _addonInstance.getName();
    }
    this.canFly = function () {
        return _addonInstance.canFly();
    }

    var _addonInstance = new addon.Animal(name, bCanFly);
}

module.exports = Animal;
