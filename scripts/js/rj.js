
const fs = require('fs')

fs.readFile('./scaledefs.json', 'utf8', (err, jsonString) => {
  if (err) {
    console.log('Error reading file from disk:', err)
    return
  }

  //const Scale Scale::major = Scale("Major", {2, 2, 1, 2, 2, 2, 1});
  // header:         static const Scale major;

  // for the cpp
  try {
    const scaleArray = JSON.parse(jsonString)
	scaleArray.forEach(function (scale, index) {
		// get rid of the spaces in the name
		var sid = scale.name.replace(/\s/g, '');
		var str = "const Scale Scale::" + sid + " = Scale("
		str += "\"" + scale.name + "\", "
		console.log(str)

		// j will be the array values as a comma delmited string
		var j = scale.intervals.join(", ")
		var is = "{ " + j  + "});\n"
		console.log(is)
	  });

  } catch (err) {
    console.log('Error parsing JSON string:', err)
  }

  // for the header
  try {
    const scaleArray = JSON.parse(jsonString)
	scaleArray.forEach(function (scale, index) {
		var sid = scale.name.replace(/\s/g, '');
		var str = "static const Scale " + sid + ";"
		console.log(str)
	  });

  } catch (err) {
    console.log('Error parsing JSON string:', err)
  }

