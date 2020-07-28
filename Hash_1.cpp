//완주하지 못한 선수
string solution(vector<string> participant, vector<string> completion)
{
	unordered_map<string, int> participants;

	//참가자 0+1 = 1
	for (string name : participant)
		++participants[name];

	//참가자 중 완주자 1-1 = 0
	for (string name : completion)
		--participants[name];

	//참가자 중 완주하지 못한 사람은 1
	for (auto pair : participants)
		if (pair.second > 0)
			return pair.first;
}