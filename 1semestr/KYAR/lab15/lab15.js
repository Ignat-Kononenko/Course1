let onePicture = document.getElementById('ones').addEventListener('click', function(){
document.querySelector("#ones").style.border="10px solid red";
})
let twoPicture = document.getElementById('two').addEventListener('mouseover',function(){
document.querySelector("#two").style.backgroundImage="url('https://islam.ru/sites/default/files/img/obshestvo/2013/09/priroda03.jpg')";
})
let two_Picture = document.getElementById('two').addEventListener('mouseout',function(){
    document.querySelector("#two").style.backgroundImage="url('https://img.freepik.com/premium-photo/wooden-bridge-in-blue-lake_104337-8600.jpg')";
})
document.getElementsByClassName("three")[0].title= "Закат на море";