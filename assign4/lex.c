#include <stdio.h>
#include <ctype.h>

enum state { start, identifier, integer, build_id, build_num, stop, build_dead, invalid };

enum state transition(enum state, char);

void main()
{
	FILE *input, *output;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
    enum state current_state = start;
    char transition_char = ' ';

    do
    {
        if(current_state == identifier)
        {
            printf(" – Identifier\n");
            fprintf(output, " – Identifier\n");
            current_state = start;
        }
        else if(current_state == integer)
        {
            printf(" – Number\n");
            fprintf(output, " – Number\n");
            current_state = start;
        }
        else if(current_state == invalid)
        {
            printf(" – Invalid\n");
            fprintf(output, " – Invalid\n");
            current_state = start;
        }

        fscanf(input, "%c", &transition_char);

        if(transition_char != ' ' || transition_char != '.')
        {
            printf("%c", transition_char);
            fprintf(output, "%c", transition_char);
        }

        current_state = transition(current_state, transition_char);
    } while (current_state != stop);
    
    fclose(input);
    fclose(output);
}

enum state transition(enum state current, char transition)
{
    if(current == start)
    {
        if(isdigit(transition))
            return build_num;

        if(isalpha(transition))
            return build_id;

        if(transition == '.')
            return stop;

        if(transition == ' ')
            return start;
        else
            return build_dead;
    }

    if(current == build_id)
    {
        if(isdigit(transition))
            return build_id;

        if(isalpha(transition) || transition == '_')
            return build_id;

        if(transition == ' ')
            return identifier;
        else
         return build_dead;
    }

    if(current == build_num)
    {
        if(isdigit(transition))
            return build_num;
            
        if(isalpha(transition))
        	return build_dead;
        	
        if(transition == ' ')
            return integer;
        else
         return build_dead;

    }
    
    if(current == build_dead)
    {
        if(isdigit(transition))
            return build_dead;
            
        if(isalpha(transition))
        	return build_dead;
        	
        if(transition == ' ')
            return invalid;
        else
         return build_dead;
    }

    return stop;
}
