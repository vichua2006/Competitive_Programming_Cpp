// very intersting solution I found here:
// a frequency array can still handle values in the range [0,1e7]. In that case, we can just construct a segmented tree over that
// array and answer a,b queries by summing up the [a,b] interval (which produces the number of salaries in the range [a,b])
// but for 1e9, which is are the actual constrains, it is too big. Hence, we compress it: arr[i] will 