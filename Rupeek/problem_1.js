var gpxParse = require("gpx-parse");

function distance(lat1,lon1,lat2,lon2) {
  if(lat1 == lat2 && lon1 == lon2)
    { console.log("condition statisfied");
      return 0;
    }
	var R = 6371;
	var dLat = (lat2-lat1) * Math.PI / 180;
	var dLon = (lon2-lon1) * Math.PI / 180;
	var a = Math.sin(dLat/2) * Math.sin(dLat/2) +
		Math.cos(lat1 * Math.PI / 180 ) * Math.cos(lat2 * Math.PI / 180 ) *
		Math.sin(dLon/2) * Math.sin(dLon/2);
	var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
	var d = R * c;
	return d;
}


gpxParse.parseGpxFromFile("./problem1.gpx", function(error, data) {
    var segments =data.tracks[0].segments[0];
    var i = 0
    var prev = false;
    var prev_lat,prev_long,prev_time,prev_elevation;
    var maxSpeed = -1;
    var total_distance = 0;
    var total_time = 0;
    var total_time_mov = 0;
    var speed = 0;
    var elevation = 0;
    segments.forEach(function(segment){
      if(!prev)
        {prev_lat = segment.lat;
         prev_long = segment.lon;
        prev_time = segment.time.getTime();
        prev = 1;
        elevation = segment.elevation;
        }
      else{
        var distance_mv = distance(prev_lat,prev_long,segment.lat,segment.lon);
        var timeDiff = segment.time.getTime() - prev_time;
        if((distance_mv/timeDiff)>maxSpeed)
          {
            maxSpeed = distance_mv/timeDiff;
          }
        elevation = segment.elevation - elevation;
        if(distance_mv>0){
          total_time_mov = total_time_mov + timeDiff;
        }
        total_time = total_time + timeDiff;
        prev_lat = segment.lat;
        prev_long = segment.lon;
        prev_time = segment.time.getTime();
        total_distance = total_distance + distance_mv;
      }
    })
    console.log("total_distance(in km):",total_distance,"total time escaped(milliseconds):",total_time,"total_time_mov(in milliseconds)",total_time_mov,"maxSpeed (in km/milliseconds)",maxSpeed,"elevation(in m)",elevation);
});
