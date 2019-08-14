const fs = require('fs')

fs.readFile('./scaledefs.json', 'utf8', (err, jsonString) => {
  if (err) {
    console.log('Error reading file from disk:', err)
    return
  }

  // const Scale Scale::major = Scale("Major", {2, 2, 1, 2, 2, 2, 1});
  // header:         static const Scale major;

//	Scale(std::string name, std::vector<int> intervals,
//		std::vector<int> degrees, std::string spelling,
//		std::string information, std::vector<std::string> categories)

// const Scale Scale::Messiaen4thMode =
//         Scale("Messiaen 4th Mode", {1, 1, 3, 1, 1, 1, 3, 1},
//               {0, 1, 2, 5, 6, 7, 8, 11, 12}, "", "",
//               {
//                   "Symmetrical",
// 							});

try {
	const scaleArray = JSON.parse(jsonString)
	scaleArray.forEach(function(scale, index) {
		// get rid of the spaces in the name
		var sid = scale.name.replace(/\s/g, '');
		var str = 'const Scale Scale::' + sid + ' = Scale('
		str += '"' + scale.name + '", '
		console.log(str)

		// j will be the array values as a comma delmited string
		var j = scale.intervals.join(', ')
		console.log('{ ' + j + '},')

		j = scale.degrees.join(', ')
		console.log('{ ' + j + '},')

		console.log('"' + scale.spelling + '", ')
		console.log('"' + scale.information + '", ')

		// join will not quote the values
		//j = scale.categories.join()
		//j = scale.categories.toString()
		//console.log('{ ' + j + '}')
	  console.log('{ ')
		scale.categories.forEach(function(cat, index) {
			console.log('"' + cat + '", ')
		})
		console.log('}')

		console.log(");\n")

	});

} catch (err) {
	console.log('Error parsing JSON string:', err)
}

  // for the cpp
  // try {
  //   const scaleArray = JSON.parse(jsonString)
  //   scaleArray.forEach(function(scale, index) {
  //     // get rid of the spaces in the name
  //     var sid = scale.name.replace(/\s/g, '');
  //     var str = 'const Scale Scale::' + sid + ' = Scale('
  //     str += '"' + scale.name + '", '
  //     console.log(str)

  //     // j will be the array values as a comma delmited string
  //     var j = scale.intervals.join(', ')
  //     var is = '{ ' + j + '});\n'
  //     console.log(is)
  //   });

  // } catch (err) {
  //   console.log('Error parsing JSON string:', err)
  // }

  // for the header
  // try {
  //   const scaleArray = JSON.parse(jsonString)
  //   scaleArray.forEach(function(scale, index) {
  //     var sid = scale.name.replace(/\s/g, '');
  //     var str = 'static const Scale ' + sid + ';'
  //     console.log(str)
  //   });

  // } catch (err) {
  //   console.log('Error parsing JSON string:', err)
	// }

})

