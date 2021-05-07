#!/usr/bin/python3
''' count_words '''
import requests


def count_words(subreddit, word_list, after='', all_hot_words=[]):
    ''' Queries the Reddit API to count occurences of keywords '''
    try:
        url = 'https://www.reddit.com/r/{}/hot.json?after={}'
        response = requests.get(
                         url.format(subreddit, after),
                         headers={'User-Agent': 'custom'},
                         allow_redirects=False)

        if after is None:
            dict = {}
            for keyword in word_list:
                for hot_word in all_hot_words:
                    if hot_word == keyword:
                        if keyword not in dict:
                            dict[keyword] = 1
                        else:
                            dict[keyword] += 1
            for keyword in sorted(dict, key=dict.get, reverse=True):
                if dict[keyword]:
                    print('{}: {}'.format(keyword, dict[keyword]))
            return

        data = response.json().get('data')
        for child in data.get('children'):
            all_hot_words += child.get('data').get('title').lower().split()
        count_words(subreddit, word_list, data.get('after'), all_hot_words)

    except Exception:
        return
