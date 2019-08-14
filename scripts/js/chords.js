// Parse my json chord definitions from my Java and Swift libraries
// for the C++ version

const fs = require('fs')

fs.readFile('./chorddefs.json', 'utf8', (err, jsonString) => {
  if (err) {
    console.log('Error reading file from disk:', err)
    return
  }

//		"bass" : "",
		//"inversion" : 0,


  try {
    const chordArray = JSON.parse(jsonString)
    chordArray.forEach(function(chord, index) {
      // get rid of the spaces in the name
      var sid = chord.symbol.replace(/\s/g, '');
      var str = 'const Chord Chord::' + sid + ' = Chord('
			console.log(str)
			console.log('"' + chord.symbol + '", ')

      // j will be the array values as a comma delmited string
      var j = chord.aliases.join(', ')
      console.log('{ ' + j + '},')

      j = chord.intervals.join(', ')
      console.log('{ ' + j + '},')

			console.log('"' + chord.spelling + '", ')
			console.log('"' + chord.chordDescription + '"')
      console.log(');\n')
    });

  } catch (err) {
    console.log('Error parsing JSON string:', err)
  }


  // for the header
  try {
    const chordArray = JSON.parse(jsonString)
    chordArray.forEach(function(chord, index) {
      var sid = chord.symbol.replace(/\s/g, '');
      var str = 'static const Chord ' + sid + ';'
      console.log(str)
    });

  } catch (err) {
    console.log('Error parsing JSON string:', err)
	}



})
