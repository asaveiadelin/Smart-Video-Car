 $(document).ready(function()
  {
    $("button").on('click',function() 
    { 
      var name = (this.name);  
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() 
      {
        if (this.readyState == 4 && this.status == 200) 
        {
        }
      };
      xhttp.open("POST", "Butoane.php", true);
      xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
      xhttp.send("name="+this.name);
    });                   
  })