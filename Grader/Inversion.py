def count_inversions(arr):
    def merge_and_count(arr, temp_arr, left, right):
        if left >= right:
            return 0

        mid = (left + right) // 2
        inversions = 0

        # Count inversions in the left half
        inversions += merge_and_count(arr, temp_arr, left, mid)

        # Count inversions in the right half
        inversions += merge_and_count(arr, temp_arr, mid + 1, right)

        # Count split inversions during merge
        inversions += merge(arr, temp_arr, left, mid, right)

        return inversions

    def merge(arr, temp_arr, left, mid, right):
        i = left      # Left subarray index
        j = mid + 1   # Right subarray index
        k = left      # Temp array index
        inversions = 0

        # Merge two halves while counting inversions
        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp_arr[k] = arr[i]
                i += 1
            else:
                # There are (mid - i + 1) inversions because all elements
                # from arr[i] to arr[mid] are greater than arr[j]
                temp_arr[k] = arr[j]
                inversions += (mid - i + 1)
                j += 1
            k += 1

        # Copy remaining elements of the left subarray, if any
        while i <= mid:
            temp_arr[k] = arr[i]
            i += 1
            k += 1

        # Copy remaining elements of the right subarray, if any
        while j <= right:
            temp_arr[k] = arr[j]
            j += 1
            k += 1

        # Copy merged elements back into the original array
        for i in range(left, right + 1):
            arr[i] = temp_arr[i]

        return inversions

    # Temporary array for merges
    temp_arr = [0] * len(arr)
    return merge_and_count(arr, temp_arr, 0, len(arr) - 1)


# Example usage
A = [1,5,4,2,3,-1]
print("Number of inversions:", count_inversions(A))