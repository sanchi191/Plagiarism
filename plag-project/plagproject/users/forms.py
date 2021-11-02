from django import forms
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm
from django.core.files.base import File
from django.forms import ClearableFileInput
from .models import Upload
from django.views.generic.edit import CreateView

class FilesUpload(forms.Form):
    class Meta:
        model = Upload
        fields = ['files']
        widgets = {
            'files': ClearableFileInput(attrs={'multiple': True}),
        }
    # files = forms.FileField(widget=forms.ClearableFileInput(attrs={'multiple': True}))

class Files(CreateView):
    class Meta:
        model = Upload
        fields = ['files']

        def form_valid(self,form):
            obj = form.save(commit=False)
            if self.request.FILES:
                for f in self.request.FILES.getlist('files'):
                    obj = self.model.objects.create(user=str(self.request.user),files=f)
            return super(Files,self).form_valid(form)

class UserRegisterForm(UserCreationForm):
    email = forms.EmailField()

    class Meta:
        model = User
        fields = ['username', 'email', 'password1', 'password2']
