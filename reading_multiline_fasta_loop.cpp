while (true)
{
    std::getline(contig_list_file, line);
    if (nline == 0) // reading the first line
    {
        seq_name = line;
    }
    else if (line[0] == '>') // reading in middle of the file
    {
        seq_vect.emplace_back(seq_name, seq);
        seq_name = line;
        seq.clear();
    }
    else if (contig_list_file.eof()) // reading the last line
    {
        seq_vect.emplace_back(seq_name, seq);
        seq.clear();
        break;
    }
    else
    {
        seq += line;
    }
    ++nline;
}