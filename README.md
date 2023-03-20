# Teensy-Syllable-Parser
An Arduino sketch containing an algorithm to parse a word and split it into separate syllables

This was ported from https://github.com/finguist/syllabipy to work on a Teensy 4.0 Arduino based microcontroller. It should be fairly easy to make work on an Arduino Uno, or some other Arduino branded device.

This program syllabifies words based on the Sonority Sequencing Principle (SSP) https://en.wikipedia.org/wiki/Sonority_Sequencing_Principle . There are Text to Speech applicatons that could use the parsed syllables to follow speech rules, to help pronouncing text correctly.

Example word entry "justification" results in jus-ti-fi-ca-tion and assigned values of each letter are: j0u5s2t0i5f2i5c0a5t0i5o5n3 which is used in determining where each syllable is split. 

The code does make some mistakes on difficult words like "turquoise". I notice that the code has been improved here: https://github.com/Yomguithereal/talisman/blob/master/src/tokenizers/syllables/sonoripy.js , though their new code still makes mistakes for "turquoise" it does better on some other words. I will try to integrate their improvements here in the near future.
