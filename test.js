function merge(left, right) {
    const newArr = []
    while(left.length && right.length)
    {
        if(left[0] <= right[0]) {
            newArr.push(left.shift())
        } else {
            newArr.push(right.shift())
        }

    }

    return newArr.concat(left.length ? left : right)
}

function mergeSort(arr) {
    if(arr.length <= 1) {
        return arr
    }

    const length = arr.length
    const middle = Math.floor(length / 2)
    const left = arr.slice(0, middle)
    const right = arr.slice(middle)


    return merge(mergeSort(left), mergeSort(right))
}

console.log(mergeSort([4,5,6,1,3]));