const addon = require('../build/Release/animal-native');

function Animal(name) {
    this.greet = function(str) {
        return _addonInstance.greet(str);
    }

    var _addonInstance = new addon.Animal(name);
}

module.exports = Animal;
