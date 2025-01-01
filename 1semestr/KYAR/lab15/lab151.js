let one = document.querySelector('#registration').addEventListener('click', function(event){
event.preventDefault();
let form = document.querySelector('form');
let input = document.querySelectorAll('input');
let select= document.querySelectorAll('select')
let button = document.querySelector('button');
let footer = document.querySelector('footer');
let men = document.querySelector('#s');
let women = document.querySelector('#ss');
for (let i = 0; i < input.length-2; i++) { 
    text = document.createElement('p'); 
    if(input[i].checked){
        if(input[i]==men){
        text.innerText =footer.append('мужской') ;
        }
        else{
            text.innerText =footer.append('женский') ;
        }
    }
    else{
        text.innerText = input[i].value ;
    }
    
    footer.append(text) ;
   } 
   for (let i = 0; i < select.length; i++) { 
    text = document.createElement('p');
    text.innerText = select[i].value ;
    footer.append(text) ;
}

console.log(form.elements.surname.value);
console.log(form.elements.name.value);
console.log(form.elements.secondName.value);
console.log(form.elements.age.value);

let man=document.getElementById('s');
let woman = document.getElementById('ss');
if(man.checked){
    console.log('мужской');
}
else if(woman.checked){
    console.log('женский');
    
}
else{
    console.log('пол не выбран');
}
console.log(form.elements.country.value);
console.log(form.elements.knowledge.value);
console.log(form.elements.date.value);

})
