
const fs = require('fs')

fs.readFile('./scaledefs.json', 'utf8', (err, jsonString) => {
  if (err) {
    console.log('Error reading file from disk:', err)
    return
  }


  // for the map

  //const std::map<std::string, const Scale> Scale::scaleMap = {
//	std::pair<std::string, const Scale>("Major", major),
	//std::pair<std::string, const Scale>("Symmetrical Decatonic",
										//symmetricalDecatonic)};

  try {
	const scaleArray = JSON.parse(jsonString)
	console.log("const std::map<std::string, const Scale> Scale::scaleMap = {")
	scaleArray.forEach(function (scale, index) {
		var sid = scale.name.replace(/\s/g, '');
		var str = "std::pair<std::string, const Scale>(" + "\"" + scale.name + "\", "
		str += sid + "),"
		console.log(str)
	  });
	  console.log("};")

  } catch (err) {
    console.log('Error parsing JSON string:', err)
  }
})
