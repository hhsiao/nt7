// This program is a part of NT mudlib
#include <ansi.h>

#define DATA_PATH       "/data/history.o"

string *history;

int save()
{
        return save_object(DATA_PATH);
}

varargs void remove(string euid)
{
        save();
}

void add_history(string key, string id, string value)
{
        object ob;

        ob = UPDATE_D->global_find_player(id);
        if(!ob) return;//baby在此引發過錯誤，特添加此行

        history = ({ time(), key, id, value }) + history;

        addn("achievement", 1, ob);
        tell_object(ob, HIY "恭喜你獲得新的成就，你獲得了１點的成就值獎勵！\n" NOR);
        UPDATE_D->global_destruct_player(ob, 1);
        save();
}

void remove_history(int index)
{
        history = history[0..((index-1)*4)-1] + history[(index-1)*4+4..];

        save();
}

string *query_history()
{
        return copy(history);
}

void create()
{
        if( !restore_object(DATA_PATH) )
        {
                history = allocate(0);
                save();
        }
}

string query_name()
{
        return "歷史事件系統(HISTORY_D)";
}
