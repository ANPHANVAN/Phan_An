export default cons;

function cons(message, TYPE = 'log') {
    console[TYPE](message)
}