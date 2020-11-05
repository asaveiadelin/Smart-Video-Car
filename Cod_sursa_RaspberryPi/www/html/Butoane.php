<?php
      $name= $_POST["name"];

      if ($name=='Inainte')
      {
        exec('sudo python /var/www/html/Inainte.py');
      }
      if ($name=='Inapoi')
      {
        exec('sudo python /var/www/html/Inapoi.py');
      }
      if ($name=='Inainte_Dreapta')
      {
        exec('sudo python /var/www/html/Inainte_Dreapta.py');
      }
      if ($name=='Inapoi_Dreapta')
      {
        exec('sudo python /var/www/html/Inapoi_Dreapta.py');
      }
      if ($name=='Inainte_Stanga')
      {
        exec('sudo python /var/www/html/Inainte_Stanga.py');
      }
      if ($name=='Inapoi_Stanga')
      {
        exec('sudo python /var/www/html/Inapoi_Stanga.py');
      }
      if ($name=='Stop')
      {
        exec('sudo python /var/www/html/Stop.py');
      }
      if ($name=='Lumini_On')
      {
        exec('sudo python /var/www/html/Lumini_On.py');
      }
      if ($name=='Lumini_Off')
      {
        exec('sudo python /var/www/html/Lumini_Off.py');
      }
      if ($name=='Speed_1')
      {
        exec('sudo python /var/www/html/Speed_1.py');
      }
      if ($name=='Speed_2')
      {
        exec('sudo python /var/www/html/Speed_2.py');
      }
      if ($name=='Speed_3')
      {
        exec('sudo python /var/www/html/Speed_3.py');
      }
      if ($name=='Speed_4')
      {
        exec('sudo python /var/www/html/Speed_4.py');
      }
      if ($name=='Buton_Sus_Camera')
      {
        exec('sudo python /var/www/html/Sus_Camera.py');
      }
      if ($name=='Buton_Jos_Camera')
      {
        exec('sudo python /var/www/html/Jos_Camera.py');
      }
      if ($name=='Buton_Stanga_Camera')
      {
        exec('sudo python /var/www/html/Stanga_Camera.py');
      }
      if ($name=='Buton_Dreapta_Camera')
      {
        exec('sudo python /var/www/html/Dreapta_Camera.py');
      }
    ?>