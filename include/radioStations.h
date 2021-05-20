#ifndef RADIO_STATIONS_H
#define RADIO_STATIONS_H

#define MAX_STATIONS 17

// Declare a struct to hold radio stations data
// NO memory allocated yet!
//
struct RadioStat
{
	char host[64];		// host name a URL
	char path[128];		// path name
	int  port;			// port number
	char name[64];		// radio station friendly name
	bool meta;			// Do we want metadata from this station
};

// Define and initialize a few Radio Stations with their data
// Now we allocated memory!
//
struct RadioStat sRadioStat[MAX_STATIONS] =
{
	 "icecast.omroep.nl",		//0
	 "/radio1-bb-mp3",
	 80,
	 "NPO Radio 1",
	 0,

	 "icecast.omroep.nl",		//1
	 "/radio2-bb-mp3",
	 80,
	 "NPO Radio 2",
	 0,

	 "ics2hss.omroep.nl",		//2
	 "/3fm-alternative-mp3",
	 80,
	 "NPO 3FM Alternative",
	 0,
/*
	 "ics2ess.omroep.nl",		//3
	 "/3fm-serioustalent-mp3",
	 80,
	 "",
	 0,

	 "icecast.omroep.nl", 		//4
	 "/radio4-bb-mp3",
	 80,
	 "NPO Radio 4",
	 0,

	 "icecast.omroep.nl",		//5
	 "/radio4-eigentijds-mp3",
	 80,
	 "NPO Radio 4 Concerten",
	 0,

	 "ics2nss.omroep.nl",		//6
	 "/radio5-bb-mp3",
	 80,
	 "NPO Radio 5",
	 0,

	 "icecast.omroep.nl", 		//7
	 "/radio6-bb-mp3",
	 80,
	 "NPO Soul & Jazz",
	 0,

	 "icecast.omroep.nl",		//8
	 "/radio2-sterrennl-mp3",
	 80,
	 "NPO Sterren.nl",
	 0,

	"stream.antenne1.de",		//9
	"/a1stg/livestream1.aac",
	80,
	"Antenne1.de",
	1,

	"bbcmedia.ic.llnwd.net",	//10
	"/stream/bbcmedia_radio4fm_mf_q", // also mf_p works
	80,
	"BBC Radio 4",
	0,

	"stream.antenne1.de",		//11
	"/a1stg/livestream2.mp3",
	80,
	"Antenne1 128k",
	1,

	"listen.181fm.com",			//12
	"/181-beatles_128k.mp3",
	80,
	"Beatles",
	1,

	"stream-mz.planetradio.co.uk",	//13
	"/magicmellow.mp3",
	80,
	"Mellow Magic (Redirected)",
	1,

	"edge-bauermz-03-gos2.sharp-stream.com",	//14
	"/net2national.mp3",
	80,
	"Greatest Hits 112k (National)",
	1,

	"airspectrum.cdnstream1.com",	//15
	"/1302_192",
	8024,
	"Mowtown Magic Oldies",
	1,

	"live-bauer-mz.sharp-stream.com",	//16
	"/magicmellow.aac",
	80,
	"Mellow Magic (48k AAC)",
	1,
*/
};	// end sRadioStation

#endif // RADIO_STATIONS_H
