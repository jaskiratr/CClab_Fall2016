//global variables
var city = '';
var state = '';
var APIKey = 'Your API KEY HERE';

var loadWeather = function(response){

	console.log(response);

	//add an error catch before setting variables
	if(response.response.error){
		alert(response.response.error.description);
		return;
	};

	//set variables to elements of your response object
	var thisCity = response.location.city;
	var temp = Math.round(response.current_observation.temp_f) + '°';
	var weather = response.current_observation.weather;
	var icon = response.current_observation.icon_url;


	//set text of HTML elements to your variables
	$('.temperature').html(temp);
	$('.weather').html(weather);
	$('.weatherIcon').html('<img src="' + icon + '">');

	//set value of city input to response city.
	$('.currentCity').val(thisCity);

};

var setLocation = function(){
	//set the global variable 'city' to the value of .currentCity
	city = $('.currentCity').val()

	//set the global variable 'state' to the value of .currentState
	state = $('.currentState').val()

	//if the city is null or it equals '', alert the user and
	//stop running the function.
	if(city == null || city == ''){
		alert('You need to list a city!');
		return;
	};

	console.log('You want the weather for ' + city + ', ' + state);

	//call getWeather() function now that city and state are set
	getWeather();
};

var getWeather = function(){

  var myUrl = "http://api.wunderground.com/api/" + APIKey +
  "/geolookup/conditions/q/" + state + "/" + city + ".json"

	//run the ajax call and load weather on success
	$.ajax({
		url : myUrl,
		dataType : "jsonp", //JSONP is JSON with padding. Used for Cross-Browser Requests  http://stackoverflow.com/questions/2887209/what-are-the-differences-between-json-and-jsonp
		success : function(response) {
			loadWeather(response);
		}
	});
};

//init
var init = function(){

	console.log('What\'s the weather?');

	$('#submit').click(function(e){
		e.preventDefault();
		setLocation();
	});
};


//document load listener
$( document ).ready(function() {
    init(); //call init() function when the page loads
});
