$(document).on('click', 'li ', function(){
        $(this).addClass('active').siblings().removeClass('active')
    localStorage.ClassName = "active";
})
   
