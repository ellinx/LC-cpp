class TeemoAttacking(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        total = 0
        if len(timeSeries)==0:
            return total

        start = timeSeries[0]
        end = start+duration

        for time in timeSeries:
            if time>end:
                total += duration
            else:
                total += time-start

            start = time
            end = time+duration

        total += duration
        return total


#test
tmp = TeemoAttacking()
timeSeries = [1,2]
result = tmp.findPoisonedDuration(timeSeries, 2)
print(result)
