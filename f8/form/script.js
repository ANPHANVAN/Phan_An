function Validator(options) {
    let formElement = document.querySelector(options.form)

    function validate(inputElement, rule){
        let erorrMessage = rule.test(inputElement)
        let fatherElement = inputElement.parentElement
        let messageElement = fatherElement.querySelector(options.message)

        if (erorrMessage) {
            messageElement.innerHTML = erorrMessage;
            fatherElement.classList.add("invalid")
        }
        else {
            messageElement.innerHTML = "";
            fatherElement.classList.remove("invalid")
        }
    }

    if (formElement) {
        options.rules.forEach(rule => {
            let inputElement = formElement.querySelector(rule.selector)
            
            if (inputElement) { 
                inputElement.onblur = function () {
                    validate(inputElement, rule)
                }
            }
        });
    }
}

Validator.isRequired = function(selector, message) {
    return {
        selector: selector,
        message: message,
        test: function(inputElement){
            if (inputElement.value.length <= 6) {
                return message;               
            }
        }
    }
}

Validator.isEmail = function(selector, message) {
    return {
        message: message,
        selector: selector,
        test: function(inputElement){
            let re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;

            if ( re.test(inputElement.value) ) {
                // valid email
            }
            else {
                return message;
            }

        }
    }
}

Validator.isSamePassword = function(selector, message ,getPassWord) {
    return {
        selector: selector,
        message: message,
        test: function(inputElement){
            if (inputElement.value !== getPassWord() ) {
                return message
            }
        }
    }
}