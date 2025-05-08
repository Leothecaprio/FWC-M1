#!/bin/bash

# Update package lists
echo "🔄 Updating package list..."
apt update

# Install required LaTeX packages
echo "📦 Installing LaTeX and related packages..."
apt install -y \
    texlive \
    texlive-latex-extra \
    texlive-fonts-recommended \
    texlive-fonts-extra \
    texlive-xetex \
    texfot

# Done
echo "✅ LaTeX environment setup complete!"

