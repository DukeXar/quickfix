What is it?
===========

This is a fork of the http://www.quickfixengine.org/ library, optimized for FIX messages parsing performance.

It seems to me that the library has been dropped by the maintainer on sourceforge.net, as last commits are far in past. This is why I have created this repository here on github.

There are other forks of the original library here on github, but they deviated a lot from the original code that I based on (http://prdownloads.sourceforge.net/quickfix/quickfix-1.13.3.tar.gz).


How fast is it?
===============

Compared to original version 1.13.3, average message parsing time reduced from 170 microseconds to 31 microsecond (gcc version 4.1.1 20070105 (Red Hat 4.1.1-52) on Intel XEON 5130 2.0 GHz).

-- Anton Klautsan <dukexar@gmail.com>


About QuickFIX
==============

If you are interested in this package, you are probably already aware of what FIX is. If not, this simple explanation from the FIX protocol organizaion should give you enough background.

The Financial Information Exchange (FIX) Protocol is a message standard developed to facilitate the electronic exchange of information related to securities transactions. It is intended for use between trading partners wishing to automate communications.
That being said, the purpose of FIX is to make communication between financial vendors trivial, leaving them to focus on their core business. The FIX organization also specifically cites that openness has been key to their success. QuickFIX intends on expanding the openness of FIX into not just the specification of, but also the implementation of the protocol.
So what is QuickFIX? Simple. QuickFIX is a free and open source implementation of the FIX protocol. QuickFIX is not crippled, all of the source is open for all supported versions of FIX. There is no upgrade to a commercial version.

It is our hope that the trading community will work together to help lower the barrier in doing business with each other. QuickFIX is a step in that direction.

--Oren Miller oren@quickfixengine.org
