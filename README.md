# Teensy-Syllable-Parser
An algorithm for an arduino to parse a word and split it into separate syllables

This ws ported from https://github.com/finguist/syllabipy to work on a Teensy 4.0 Arduino based microcontroller. It should be easy to make work on an Arduino Uno, or some other Arduino branded device.

This program syllabifies words based on the Sonority Sequencing Principle (SSP) https://en.wikipedia.org/wiki/Sonority_Sequencing_Principle . There are Text to Speech applicatons that could use the parsed syllables to follow speech rules, to help pronouncing text correctly.
