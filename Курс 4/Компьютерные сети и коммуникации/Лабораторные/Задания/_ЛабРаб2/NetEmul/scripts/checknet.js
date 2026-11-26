var result;
var comps = computerList();
var sendPacket = 0;
var receivePacket = 0;
for ( i = 0 ; i < comps.length ; i++ ) {
        sendPacket += comps[i].receivePacketCount("eth0");
        receivePacket += comps[i].sendPacketCount("eth0");
}
print(sendPacket + " " + receivePacket);
for ( i = 0 ; i < comps.length; i++ )
    for ( j = 0 ; j < comps.length; j++ )
        if ( i != j ) comps[i].sendMessage( comps[j].ipaddress("eth0") , 5 , 0);
emulateTime();
var tempSend = 0;
var tempReceive = 0;
for ( i = 0 ; i < comps.length ; i++ ) {
        tempSend += comps[i].receivePacketCount("eth0");
        tempReceive += comps[i].sendPacketCount("eth0");
}
result = ( tempSend == sendPacket+(comps.length-1) *comps.length * 5
           && tempReceive == receivePacket + (comps.length-1) * comps.length * 5 );
result;
