if ( open ) closeScene();
newScene();
var h1 = addHub(5,0);
h1.setSocketsCount(4);
var h2 = addHub(2,2);
h2.setSocketsCount(8);
var h3 = addHub(8,2);
h3.setSocketsCount(8);
addConnection(h1, h2 , "LAN3" , "LAN8");
addConnection(h1, h3 , "LAN4" , "LAN8");
var net = new Array();
for ( i = 0 ; i < 11 ; i++) {
    if ( i == 5 ) continue;
	net[i] = addComputer(i,5);
        if ( i < 5 ) addConnection( h2 , net[i] , "LAN" + (i+1) , "eth0" );
        else addConnection( h3 , net[i] , "LAN" + (i-5) , "eth0" );
        net[i].setIp( "eth0" , "192.168.1." + (i+1) );
	net[i].setMask( "eth0" , "255.255.255.0");
}
net[0].sendMessage("192.168.1.11",50,0);
emulateTime();
net[10].sendMessage("192.168.1.1",50,0);
emulateTime();
true;

