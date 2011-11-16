Simple command line converter for colors from 24bit format (8 bit per color) to
16 bit (5 bit for red, 6 bit for green and 5 bit for blue).

<pre><code>
Usage:
	colrconv color1 color2 ... colorN
where:
	color - hex rgb, prefixed by 0x. i.e.: 0xFF00FF).
</code></pre>

Example:

<pre><code>
$ ./colrconv 0xFF00FF 0x000000 0xFF7E00 0xA52A2A
0xFF00FF -> 0x00F81F
0x000000 -> 0x000000
0xFF7E00 -> 0x00FBE0
0xA52A2A -> 0x00A145
</code></pre>

NB: You can see, that the output is 24 bit too. But first 8 bits are always '00'.

