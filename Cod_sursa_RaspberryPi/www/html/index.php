<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>Licenta</title>
    <link rel="stylesheet" href="assets/bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="assets/css/styles.css">
</head>

<body>
    <div class="text-center" id="Smart-Car-Remote-Control-Paragraph">
        <p class="text-monospace text-nowrap text-truncate text-break text-center text-primary d-flex d-sm-flex justify-content-center align-items-center justify-content-sm-center align-items-sm-center text-center" style="margin-top: 77px;margin-bottom: -3px;"><strong>Smart Car Remote Control</strong></p>
    </div>
    <ul id="mainNav">
        <li class="active"><a href="#Butoane-Comenzi-Masina" style="text-decoration:none">Car</a></li>
        <li><a href="#Butoane-Comenzi-Camera" style="text-decoration:none">Camera</a></li>
        <li><a href="#Speed-Light" style="text-decoration:none">Speed &amp; Light</a></li>
        <li class="animation"></li>
    </ul>
    <div id="Telecomanda" class="container mt-2 Telecomanda">
        <div class="row text-center">
            <div id="Butoane-Comenzi-Masina" class="col-lg-4 col-xl-4 justify-content-center">
                <div id="row-Buton-Inainte" class="row-Buton-Inainte"><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Inainte" name="Inainte"><strong>↑</strong></button></div>
                <div id="row-Stanga-Dreapta" class="row">
                    <div id="Stanga" class="col-xl-4 col-lg-4"><button class="btn text-center d-flex justify-content-center align-items-md-center" id="Inainte-Stanga" name="Inainte_Stanga">↰</button><button class="btn text-center d-flex justify-content-center align-items-center" id="Inapoi-Stanga"
                            name="Inapoi_Stanga">↲</button></div>
                    <div id="Stop" class="col-xl-4 col-lg-4"><button class="btn text-center d-inline d-sm-flex mx-auto justify-content-sm-center align-items-sm-center" id="stop" name="Stop">STOP</button></div>
                    <div id="Dreapta" class="col-xl-4 col-lg-4"><button class="btn text-center d-flex justify-content-center order-1 m-auto align-items-md-center" id="Inainte-Dreapta" name="Inainte_Dreapta">↱</button><button class="btn text-center d-flex justify-content-center align-items-center mx-auto"
                            id="Inapoi-Dreapta" name="Inapoi_Dreapta">↳</button></div>
                </div>
                <div id="row-Buton-Inapoi" class="row-Buton-Inapoi"><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Inapoi" name="Inapoi"><strong>↓</strong><br></button></div>
            </div>
            <div id="Live" class="col-lg-4 col-xl-4 img-container"><img class="img-fluid" id="Live-Video-Image" src="http://192.168.100.12:8000/stream.mjpg"></div>
            <div id="Butoane-Comenzi-Camera" class="col-lg-4 col-xl-4 justify-content-center">
                <div id="row-Sus" class="row"><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Sus" name="Buton_Sus_Camera"><strong>↑</strong></button></div>
                <div id="row-Stanga-Dreapta-Camera" class="row">
                    <div id="Stanga-Camera" class="col-xl-4 col-lg-3"><button class="btn d-flex justify-content-center align-items-center mx-auto align-items-md-center" id="Buton-Stanga-Camera" name="Buton_Stanga_Camera"><br><strong>←</strong><br></button></div>
                    <div id="Dreapta-Camera" class="col-xl-4 col-lg-4"><button class="btn text-center d-flex justify-content-center align-items-center mx-auto align-items-md-center" id="Buton-Dreapta-Camera" name="Buton_Dreapta_Camera"><br><strong>→</strong><br></button></div>
                </div>
                <div id="row-Jos" class="row"><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Buton-Jos-Camera" name="Buton_Jos_Camera"><strong>↓</strong><br></button></div>
            </div>
        </div>
    </div>
    <div id="Speed-Light">
        <div class="text-center" id="Paragraph-Speed">
            <p class="text-monospace text-nowrap text-truncate text-break text-center text-primary d-flex d-sm-flex justify-content-center align-items-center justify-content-sm-center align-items-sm-center" id="Paragraph-speed">Speed</p>
        </div>
        <div class="table-responsive table-borderless text-center d-flex flex-row justify-content-center align-items-center mx-auto" id="Table-Speed">
            <table class="table table-bordered">
                <tbody>
                    <tr>
                        <td><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Speed_1" style="margin-top: 16px;width: 60px;padding-right: 31px;padding-left: 30px;" name="Speed_1">1</button></td>
                        <td><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Speed_2" style="margin-top: 16px;width: 60px;padding-right: 31px;padding-left: 30px;" name="Speed_2">2</button></td>
                        <td><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Speed_3" style="margin-top: 16px;width: 60px;padding-right: 31px;padding-left: 30px;" name="Speed_3">3</button></td>
                        <td><button class="btn text-center d-flex justify-content-center align-items-center mx-auto" id="Speed_4" style="margin-top: 16px;width: 60px;padding-right: 31px;padding-left: 30px;" name="Speed_4">4</button></td>
                    </tr>
                </tbody>
            </table>
        </div>
        <div class="text-center" id="Paragraph-Light">
            <p class="text-monospace text-nowrap text-truncate text-break text-center text-primary d-flex d-sm-flex justify-content-center align-items-center justify-content-sm-center align-items-sm-center" id="Paragraph-light">Light</p>
        </div>
        <div class="table-responsive table-borderless text-center d-flex flex-row justify-content-center align-items-center mx-auto" id="Table-Light">
            <table class="table table-bordered">
                <tbody>
                    <tr>
                        <td><button class="btn text-center d-flex justify-content-center order-1 m-auto align-items-md-center" id="Lumini-On" style="margin-top: 15px;" name="Lumini_On">On</button></td>
                        <td><button class="btn text-center d-flex justify-content-center order-1 m-auto align-items-md-center" id="Lumini-Off" style="margin-top: 15px;" name="Lumini_Off">Off</button></td>
                    </tr>
                </tbody>
            </table>
        </div>
    </div>
    <script src="assets/js/jquery.min.js"></script>
    <script src="assets/bootstrap/js/bootstrap.min.js"></script>
    <script src="assets/js/Load.js"></script>
    <script src="assets/js/mainNav.js"></script>
    <script src="assets/js/mainNavRemember.js"></script>
    <script src="assets/js/Send_Name.js"></script>
</body>

</html>
