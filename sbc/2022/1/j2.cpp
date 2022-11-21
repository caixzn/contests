#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

int maxv(int x){
    if (x > 10)
        return 10;
    return x;
}

void control(){
    int n;
    cin >> n;
    vi cards (15);
    int joao = 0, maria = 0;
    int a, b;
    cin >> a >> b;
    cards[a]++, cards[b]++;
    joao += (maxv(a) + maxv(b));
    cin >> a >> b;
    cards[a]++, cards[b]++;
    maria += (maxv(a) + maxv(b));

    for (int i = 0; i < n; i++){
        int new_card;
        cin >> new_card;
        maria += maxv(new_card);
        joao += maxv(new_card);
        cards[new_card]++;
    }

    // Verificar se maria ganha
    int m_diff = 23 - maria;
    int j_diff = 23 - joao;

    // Se maria tem carta menor
    if (m_diff <= j_diff){
        if (cards[m_diff] < 4)
            cout << m_diff << '\n';
        else 
            cout << "-1\n";
        return;
    }
    // Se maria tem carta maior
    for (int i = j_diff + 1; i <= 10; i++){
        if (cards[i] < 4){
            maria + maxv(i) <= 23 ? cout << i << '\n' : cout << "-1\n";
            return;
        }
    }
    cout << "-1\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    control();
    return 0;
}