class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        word = str.split (' ')
        mymap = {}
        n = len (pattern)
        if len (pattern) != len (word) : 
            return False
        for i in xrange (n) :
            if pattern[i] in mymap :
                if mymap[pattern[i]] != word[i] :
                    return False;
            else :
                mymap[pattern[i]] = word[i]
        uniq = mymap.values ()
        if len (uniq) != len (set (uniq)) :
            return False
        return True
        