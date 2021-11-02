from django.db import reset_queries
from django.shortcuts import render, redirect
from django.contrib import messages
from django.contrib.auth.decorators import login_required
from .forms import UserRegisterForm
from django.core.files.storage import FileSystemStorage
from .forms import FilesUpload
from .models import Upload
from .forms import Files
from django.views.generic.edit import FormView
import os
from .basics import common
import matplotlib.pyplot as plt


class FileFieldView(FormView):
    form_class = FilesUpload
    template_name = 'users/upload.html'
    success_url = '/upload/'

    def post(self, request, *args, **kwargs):
        form_class = self.get_form_class()
        form = self.get_form(form_class)
        files = request.FILES.getlist('files')
        # print(files)
        if form.is_valid():
            for f in files:
                file_instance = Upload(user=str(request.user),files=f)
                file_instance.save()
        print(request.user)
        path = "../plagproject/media1/" + str(request.user)
        #print(path)
        mat = common(path)
        #print(mat)
        plt.imshow(mat)
        plt.colorbar()
        plt.show()
        return render(request, 'users/upload.html',{'form': form})

@login_required
def upload(request):
    print(request)
    if request.method=='POST':
        form = FilesUpload(request.POST, request.FILES)
        files = request.FILES.getlist('files')
        if form.is_valid():
            for f in files:
                file_instance = Upload(user=str(request.user),files=f)
                file_instance.save()

        else:
            form = FilesUpload()

    return render(request, 'users/upload.html',{'form': form})



def register(request):
    if request.method == 'POST':
        form = UserRegisterForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get('username')
            messages.success(request, f'Account created for {username}!')
            return redirect('login')
    else:
        form = UserRegisterForm()
    return render(request, 'users/register.html', {'form': form})
