let commentAPI = "http://localhost:3000/comments"
let coursAPI = 'http://localhost:3000/courses'

function getCourses(callback){
    fetch(coursAPI)
        .then((responsive)=>responsive.json())
        .then(callback)
}

// render li when you have a data
function renderCourse(courses) {
    console.log(courses)
    let html = '';
    courses.forEach(course => {
        html += `
        <li id = "id-${course.id}">
            <h2>${course.course}</h2>
            <p>${course.description}</p>
            <button type="submit" class="delete-submit" value = "${course.id}">Delete Course</button>
        </li>
        `
    });

    return document.getElementsByTagName("ul")[0].innerHTML = html;
}

function addCourse(event){
    event.preventDefault(); // Ngăn chặn tải lại trang
    let form = document.getElementById("addCourse");

    let data = {}; // Tạo object để lưu dữ liệu
    new FormData(form).forEach((value, key) => {
        data[key] = value; // Lưu giá trị input vào object
    });

    // Send the POST request using fetch
    fetch(coursAPI, {
        method: "POST",
        headers: {
        "Content-Type": "application/json"
        },
        body: JSON.stringify(data)
    })
        .then((response) => response.json())
        .then((data) => getCourses(renderCourse))
        .catch((error) => console.error("Error:", error));

}


// action source programmer
function run(){
    getCourses(renderCourse);

    document.getElementById("addCourse").addEventListener("submit", addCourse);

    document.getElementById("courseContainer").addEventListener("click", deleteCourse);
    
}

function deleteCourse(event){
    if(event.target.classList.contains("delete-submit")) {
        event.preventDefault();
        let valuesId = event.target.value;
        fetch(`http://localhost:3000/courses/${valuesId}`, {
            method: "DELETE",
            headers: {
                "Content-Type": "application/json"
            }
        })
            .then(response=>response.json())
            .then(()=>{
                document.getElementById(`id-${valuesId}`).remove();
            })
            .catch(error => console.error("Error:", error));
    }


        
}

document.addEventListener("DOMContentLoaded", function () {
    run();
});

run()
