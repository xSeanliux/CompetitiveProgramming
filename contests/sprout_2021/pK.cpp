#include "Poker.h"
#define pb push_back

bool cmp1(const Card &c1, const Card &c2) {
    // 1 < 2 < ..... < 13
    return c1.number < c2.number;
}

bool cmp2(const Card &c1, const Card &c2) {
    // 2 < ..... < 13 < 1
    return (c1.number + 11) % 13 < (c2.number + 11) % 13;
}

int f(int x) {
    return (x + 11) % 13 + 1;
}

int get_high_card_point(vector<Card> v) {
    sort(v.begin(), v.end(), cmp2); reverse(v.begin(), v.end());
    int ret = 0;
    for (Card c: v) {
        ret *= 15;
        ret += f(c.number);
    }
    return ret;
}

int is_flush(vector<Card> v) {
    for (int i = 0; i < 5; ++i) {
        if (v[i].suit != v[0].suit) return 0;
    }
    return get_high_card_point(v);
}

int is_straight(vector<Card> v) {
    sort(v.begin(), v.end(), cmp1);
    // check normal straight
    if (v[0].number + 1 == v[1].number && v[1].number + 1 == v[2].number && v[2].number + 1 == v[3].number && v[3].number + 1 == v[4].number) {
        return f(v[4].number);
    }
    // check 10 J Q K A
    if (v[0].number == 1 && v[1].number == 10 && v[2].number == 11 && v[3].number == 12 && v[4].number == 13) {
        return 13;
    }
    return 0;
}

int is_four_of_a_kind(vector<Card> v) {
    sort(v.begin(), v.end(), cmp2);
    if (v[0].number == v[1].number && v[1].number == v[2].number && v[2].number == v[3].number) {
        return f(v[0].number) * 15 + f(v[4].number);
    }
    if (v[1].number == v[2].number && v[2].number == v[3].number && v[3].number == v[4].number) {
        return f(v[4].number) * 15 + f(v[0].number);
    }
    return 0;
}

int is_full_house(vector<Card> v) {
    sort(v.begin(), v.end(), cmp2);
    if (v[0].number == v[1].number && v[1].number == v[2].number && v[3].number == v[4].number) {
        return f(v[0].number) * 15 + f(v[3].number);
    }
    if (v[2].number == v[3].number && v[3].number == v[4].number && v[0].number == v[1].number) {
        return f(v[2].number) * 15 + f(v[0].number);
    }
    return 0;
}

int is_three_of_a_kind(vector<Card> v) {
    sort(v.begin(), v.end(), cmp2);
    if (v[0].number == v[1].number && v[1].number == v[2].number) {
        return f(v[0].number) * 300 + get_high_card_point({v[3], v[4]});
    }
    if (v[1].number == v[2].number && v[2].number == v[3].number) {
        return f(v[1].number) * 300 + get_high_card_point({v[0], v[4]});
    }
    if (v[2].number == v[3].number && v[3].number == v[4].number) {
        return f(v[2].number) * 300 + get_high_card_point({v[0], v[1]});
    }
    return 0;
}

int is_two_pair(vector<Card> v) {
    sort(v.begin(), v.end(), cmp2);
    if (v[0].number == v[1].number && v[2].number == v[3].number) {
        return get_high_card_point({v[0], v[2]}) * 300 + f(v[4].number);
    }
    if (v[0].number == v[1].number && v[3].number == v[4].number) {
        return get_high_card_point({v[0], v[3]}) * 300 + f(v[2].number);
    }
    if (v[1].number == v[2].number && v[3].number == v[4].number) {
        return get_high_card_point({v[1], v[3]}) * 300 + f(v[0].number);
    }
    return 0;
}

int is_one_pair(vector<Card> v) {
    sort(v.begin(), v.end(), cmp2);
    for (int i = 0; i < 4; ++i) {
        if (v[i].number == v[i + 1].number) {
            return f(v[i].number) * 15 * 15 * 15 * 15 * 15 + get_high_card_point(v);
        }
    }
    return 0;
}

pair<int, int> get_card_value(vector<Card> v) {
    int v1 = is_flush(v);
    int v2 = is_straight(v);
    if (v1 > 0 && v2 > 0) {
        // straight flush
        return make_pair(9, v2);
    }
    int v3 = is_four_of_a_kind(v);
    if (v3 > 0) {
        return make_pair(8, v3);
    }
    int v4 = is_full_house(v);
    if (v4 > 0) {
        return make_pair(7, v4);
    }
    if (v1 > 0) {
        return make_pair(6, v1);
    }
    if (v2 > 0) {
        return make_pair(5, v2);
    }
    int v5 = is_three_of_a_kind(v);
    if (v5 > 0) {
        return make_pair(4, v5);
    }
    int v6 = is_two_pair(v);
    if (v6 > 0) {
        return make_pair(3, v6);
    }
    int v7 = is_one_pair(v);
    if (v7 > 0) {
        return make_pair(2, v7);
    }
    return make_pair(1, get_high_card_point(v));
}

vector<Card> get_random_card() {
	vector<Card> card_deck;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 13; ++j) {
            card_deck.push_back(Card(i, j));
        }
    }

    mt19937 rng(7875);
    shuffle(card_deck.begin(), card_deck.end(), rng);
    vector<Card> arr;
    arr.pb(card_deck[0]);
    arr.pb(card_deck[1]);
    return arr;
}

void play() {
	bool flag;
	int cnt;
    vector<Card> ret = get_init_card(), tmp, ran, arr;
    cnt = 0;
    for (int i = 0; i < 100; i++) {
    	ran = get_random_card();
    	arr = tmp, arr.insert(arr.end(), ran.begin(), ran.end());
    	if (get_card_value(ret) > get_card_value(arr)) cnt++;
	}
	flag = cnt >= 70;
    bet1(flag ? 100000 : 0);

    vector<Card> river_1 = get_river_card_1();
    ret.pb(river_1[0]); tmp.pb(river_1[0]);
    ret.pb(river_1[1]); tmp.pb(river_1[1]);
    ret.pb(river_1[2]); tmp.pb(river_1[2]);
    cnt = 0;
    for (int i = 0; i < 100; i++) {
    	ran = get_random_card();
    	arr = tmp, arr.insert(arr.end(), ran.begin(), ran.end());
    	if (get_card_value(ret) > get_card_value(arr)) cnt++;
	}
	flag = cnt >= 70;
    bet2(flag ? 100000 : 0);

    vector<Card> river_2 = get_river_card_2();
    ret.pb(river_2[0]); tmp.pb(river_2[0]);
    cnt = 0;
    for (int i = 0; i < 100; i++) {
    	ran = get_random_card();
    	arr = tmp, arr.insert(arr.end(), ran.begin(), ran.end());
    	if (get_card_value(ret) > get_card_value(arr)) cnt++;
	}
	flag = cnt >= 70;
    bet3(flag ? 100000 : 0);

    vector<Card> river_3 = get_river_card_3();
    ret.pb(river_3[0]); tmp.pb(river_3[0]);
    cnt = 0;
    for (int i = 0; i < 100; i++) {
    	ran = get_random_card();
    	arr = tmp, arr.insert(arr.end(), ran.begin(), ran.end());
    	if (get_card_value(ret) > get_card_value(arr)) cnt++;
	}
	flag = cnt >= 70;
    bet4(flag ? 100000 : 0);

    get_result();
}
