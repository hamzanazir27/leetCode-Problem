class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Step 1: Check if total cards can be evenly divided into groups
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        // Step 2: Count frequency of each card
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        
        // Step 3: Greedy approach - always start with smallest available card
        for (auto& pair : count) {
            int startCard = pair.first;
            int frequency = pair.second;
            
            // If this card is already used up, skip it
            if (frequency == 0) continue;
            
            // Try to form 'frequency' number of groups starting with 'startCard'
            for (int i = 0; i < frequency; i++) {
                // Try to form one group: [startCard, startCard+1, ..., startCard+groupSize-1]
                for (int j = 0; j < groupSize; j++) {
                    int neededCard = startCard + j;
                    
                    // Check if we have this card available
                    if (count[neededCard] <= 0) {
                        return false; // Can't form the group
                    }
                    
                    // Use this card (decrease its count)
                    count[neededCard]--;
                }
            }
        }
        
        return true; // All cards successfully used in valid groups
    }
};