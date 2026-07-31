class Solution {
	public:
	string findOrder(vector<string> &words) {
		// Store all unique characters present in the dictionary
		unordered_set<char> chars;
		
		for (string &s : words) {
			for (char &ch : s) {
				chars.insert(ch);
			}
		}
		
		// Total number of unique characters
		int V = chars.size();
		
		// Adjacency list representing precedence between characters
		unordered_map<char, string> adj(V);
		
		// Stores indegree of each character
		unordered_map<char, int> indegree;
		
		// Build the graph by comparing adjacent words
		for (int i = 0; i < words.size() - 1; i++) {
			string w1 = words[i];
			string w2 = words[i + 1];
			
			for (int j = 0; j < w1.size(); j++) {
				
				// Invalid case:
				// If the second word is a prefix of the first,
				// then no valid ordering exists
				if (j == w2.size())
					return "";
				
				// The first differing characters determine the ordering
				if (w1[j] != w2[j]) {
					adj[w1[j]].push_back(w2[j]);
					indegree[w2[j]]++;
					break;
				}
			}
		}
		
		// Initialize queue with all characters having zero indegree
		queue<char> q;
		
		for (char ch : chars) {
			if (indegree.count(ch) == 0) {
				q.push(ch);
			}
		}
		
		string ans = "";
		
		// Perform Kahn's Topological Sort
		while (!q.empty()) {
			char cur = q.front();
			q.pop();
			
			ans.push_back(cur);
			
			// Reduce indegree of all neighboring characters
			for (char v : adj[cur]) {
				indegree[v]--;
				
				// Push into queue when indegree becomes zero
				if (indegree[v] == 0)
					q.push(v);
			}
		}
		
		// If all characters are processed, return the ordering.
		// Otherwise, a cycle exists and no valid ordering is possible.
		return ans.size() == chars.size() ? ans : "";
	}
};
