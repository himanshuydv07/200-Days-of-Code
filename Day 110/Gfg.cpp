        vector<int> result;
        // The array initially contains only a single value, 0
        result.push_back(0); 
        
        int current_xor = 0;
        
        // Process each query
        for (const auto& query : queries) {
            int type = query[0];
            int x = query[1];
            
            if (type == 0) {
                // To ignore past XORs, we store it as (x ^ current_xor)
                result.push_back(x ^ current_xor);
            } else if (type == 1) {
                // Update the cumulative XOR mask
                current_xor ^= x;
            }
        }
        
        // Apply the final accumulated XOR mask to all elements
        for (int& val : result) {
            val ^= current_xor;
        }
        
        // Sort the array as required by the prompt
        sort(result.begin(), result.end());
        
        return result;
