//#include <sstream>

vector<string> explode(string const& s, char delim) {
	vector<string> result;
	istringstream iss(s);
	for (string token; getline(iss, token, delim); )
	{
		result.push_back(move(token));
	}
	return result;
}