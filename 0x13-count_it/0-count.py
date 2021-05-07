#!/usr/bin/python3
""" this doesn't work yet
"""
import json
import pandas as pd
import requests

subreddit = 'python'
limit = 100
timeframe = 'all'  # hour, day, week, month, year, all
listing = 'random'  # controversial, best, hot, new, random, rising, top


def get_reddit(subreddit, listing, limit, timeframe):
    """ get subreddit according to parameters
    """
    try:
        base_url = f'https://www.reddit.com/r/{subreddit}/\
                {listing}.json?limit={limit}&t={timeframe}'
        request = requests.get(base_url, headers={'User-agent': 'yourbot'})
    except Exception:
        print('An Error Occured')
    return request.json()


def get_post_titles(r):
    """ get titles in subreddit
    """
    posts = []
    for post in r['data']['children']:
        x = post['data']['title']
        posts.append(x)
    return posts


def get_results(r):
    """ get results of
    """
    myDict = {}
    for post in r['data']['children']:
        myDict[post['data']['title']] = \
                {'url': post['data']['url'], 'score': post['data']['score'],
                 'comments': post['data']['num_comments']}
    df = pd.DataFrame.from_dict(myDict, orient='index')
    return df


if __name__ == '__main__':
    r = get_reddit(subreddit, listing, limit, timeframe)
    df = get_results(r)
