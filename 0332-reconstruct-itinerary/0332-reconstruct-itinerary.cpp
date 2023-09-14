class Solution {
    void depthFirstSearch(string airport, unordered_map<string, multiset<string>>& adjGraph,
    vector<string>&itinerary) {
        multiset<string>& destinations = adjGraph[airport];
        while (!destinations.empty()) {
            string nextDestination = *(adjGraph[airport].begin());
            adjGraph[airport].erase(adjGraph[airport].begin());
            depthFirstSearch(nextDestination, adjGraph, itinerary);
        }
        itinerary.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adjGraph;
        for (vector<string>& ticket: tickets) {
            adjGraph[ticket[0]].insert(ticket[1]);
        }
        vector<string> itinerary;
        depthFirstSearch("JFK", adjGraph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};