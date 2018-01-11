//Define Global Settings.
var showIOS = true;				//this variable is used to control whether we show ios code to the user first or the android code

function uuid(){
	var result='';
	for(var i=0; i<32; i++){
		result += Math.floor(Math.random()*16).toString(16).toUpperCase();
	}
	return result;
}

$(document).ready(function(){
		$(".tabContent[active='false']").hide();
		
		// set up the bar information					
		$(".code_type_bar").each(function(index){
			var to = $(this).attr("to");
			var uniqueId = uuid();
			var code_type_bar = "<div name='anchor"+ uniqueId +"' class='tabs'>"+
									"<a href='#anchor"+ uniqueId +"' to='"+ to +"|ios' group='"+ to +"|a|group' >iOS</a>" +
									"<a href='#anchor"+ uniqueId +"' to='"+ to +"|android' group='"+ to +"|a|group' >Android</a>"+
								"</div>";
			$(this).html(code_type_bar);
			if(showIOS){$(".tabs a[to='"+to+"|ios']").addClass("tabActive");}
		});

		$(".code_type_bar_ios_only").each(function(index){
			var to = $(this).attr("to");
			var uniqueId = uuid();
			var code_type_bar = "<div name='anchor"+ uniqueId +"' class='tabs'>"+
									"<a href='#anchor"+ uniqueId +"' to='"+ to +"|ios' group='"+ to +"|a|group' >iOS</a>" +
								"</div>";
			$(this).html(code_type_bar);
			if(showIOS){$(".tabs a[to='"+to+"|ios']").addClass("tabActive");}
		});
		
		// set up the content information
		$(".ios").each(function(index){
			var to = $(this).attr("to");
			var content = $(this).html();
			var enhancedContent = 	"<div class='tabContent' to='"+ to +"|ios|content' group='"+ to +"|content|group'>" +
									"<pre><code>" + content + "</code><br/></pre>" +
									"</div>";
			$(this).html(enhancedContent);
			if(!showIOS){$(".tabContent[to='"+to+"|ios|content']").hide();}
		});
		
		$(".android").each(function(index){
			var to = $(this).attr("to");
			var content = $(this).html();
			var enhancedContent = 	"<div class='tabContent' to='"+ to +"|android|content' group='"+ to +"|content|group'>" +
									"<pre><code>" + content + "</code><br/></pre>" +
									"</div>";
			$(this).html(enhancedContent);
			if(showIOS){$(".tabContent[to='"+to+"|android|content']").hide();}
		});
		
		
		
		// register the click events for the code navigation bar title
		$(".tabs a").click(function(){
			var to = $(this).attr("to");
			var key = to.split("|")[0];
			$(".tabs a[group='"+ key +"|a|group']").removeClass("tabActive");
			$(".tabs a[group='"+ key +"|a|group']").addClass("tabInActive");
			$(this).removeClass("tabInActive");
			$(this).addClass("tabActive");
			$(".tabContent[group='"+ key +"|content|group']").hide();
			$(".tabContent[to='"+ to +"|content']").show();
		});
		
		//load and build the menu for the documents
		buildContent();
	})
	
function buildContent(){
		if(!$('#menu').length){
			var content = $('body').html();
			$("html").css("height","100%");
			$("body").css("height","100%").css("margin","0px").css("padding","0px");
			$("body").css("width", $(window).width()+"px");
			$('body').empty();
			var newContent = "<div id='menu' style='float:left;width:25%;height:100%;background-color:#eee;margin-right:10px;'></div>";
			newContent += "<div id='content' style='float:left;width:70%;height:100%;'></div>";
			$('body').html(newContent);
			$('#content').html(content);
			$("h2, h3").each(function(){
				if($(this).is('h2')){
					$("#menu").append("<div style='float:left;width:100%;height:40px;display:table;background-color:#ddd;border-bottom:1px solid #eee;cursor:pointer' onclick='navigateHere(\""+ $(this)[0].id +"\")'><span style='display:table-cell;vertical-align:middle'>&nbsp;&nbsp;&nbsp;&#9724;&nbsp;&nbsp;"+  $(this).text() +"</span></div>");
				}else if($(this).is('h3')){
					$("#menu").append("<div style='float:left;width:100%;height:40px;display:table;background-color:#ddd;border-bottom:1px solid #eee;cursor:pointer' onclick='navigateHere(\""+ $(this)[0].id +"\")'><span style='display:table-cell;vertical-align:middle'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9656;&nbsp;&nbsp;"+  $(this).text() +"</span></div>");
				}	
			});
		}
}
	
function navigateHere(objId){
		$("html,body").animate({scrollTop: $("#"+objId).offset().top}, 500);
}