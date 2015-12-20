class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        a = path.strip ().split ('/')
        s = []
        for b in a :
            if b == '.' or b == '' : continue
            if b == '..' : 
                if len (s) != 0 : s.pop ()
            else : s.append (b)
        return '/' + '/'.join(s)
        