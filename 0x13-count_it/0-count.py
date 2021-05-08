#!/usr/bin/python3
"""recursive function that queries the Reddit API"""
import requests


def count_words(subreddit, list, after="", count={}):
    """recursive function that queries the Reddit API"""
    if after is None:
        return []
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64)\
                AppleWebKit/537.36 (KHTML, like Gecko)Chrome/70.0.3538.7\
                7 Safari/537.36'}
    if after:
        url += '?after={}'.format(after)
    r = requests.get(url, headers=headers, allow_redirects=False)
    if str(r) != '<Response [200]>':
        return None
    data = r.json().get('data')
    after = data.get('after')
    list_underlist = data.get('children')
    for under_list in list_underlist:
        title = under_list.get('data').get('title')
        for mot in list:
            occ = title.lower().split().count(mot.lower())
            if occ > 0:
                if mot in count:
                    count[mot] += occ
                else:
                    count[mot] = occ
    if after is None:
        if not len(count) > 0:
            return
        it = sorted(count.items(), key=lambda kv: (-kv[1], kv[0]))
        for key, value in it:
            print('{}: {}'.format(key.lower(), value))
    else:
        return count_words(subreddit, list, after, count)
