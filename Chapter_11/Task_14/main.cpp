int decrement(int num)
{
    if (num == 0)
    {
        return 0;
    }
    
    return decrement(--num);
}

int main()
{
    decrement(7);

    return 0;
}